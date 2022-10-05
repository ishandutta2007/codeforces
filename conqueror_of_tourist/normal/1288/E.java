import java.util.Arrays;
import java.util.Scanner;

public class CF1288E {
	static int[] segtree, left, right;
	
	public class Event implements Comparable<Event>{
		int index;
		int val;
		
		Event (int val, int index){
			this.val = val;
			this.index = index;
		}

		@Override
		public int compareTo(Event o) {
			int res = Integer.compare(val, o.val);
			return res;
		}
		
	}
	
	public static void build(int lo, int hi, int seg) {
		left[seg] = lo;
		right[seg] = hi;
		if (lo == hi - 1) 
			return;
		int mid = (lo + hi)/2;
		build(lo, mid, 2 * seg + 1);
		build(mid, hi, 2 * seg + 2);
		segtree[seg] = segtree[2 * seg + 1] + segtree[2 * seg + 2];
	}
	
	//Currently adds upd to index i
	public static void update(int i, int upd, int seg) {
		if (left[seg] <= i && i < right[seg]) {
			if (left[seg] == right[seg] - 1) {
				segtree[seg] += upd;
			}
			else {
				update(i, upd, 2 * seg + 1);
				update(i, upd, 2 * seg + 2);
				segtree[seg] += upd;
			}
		}
	}
	
	public static int query(int seg, int i, int j) {
		if (i >= right[seg] || j <= left[seg]) {
			return 0;
		}
		if (left[seg] >= i && right[seg] <= j) {
			return segtree[seg];
		}
		return query(2 * seg + 1, i, j) + query(2 * seg + 2, i, j);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		int size = n + m;
		int[] currpos = new int[n];
		int[] mins = new int[n];
		int[] maxs = new int[n];
		
		for(int i = 0; i < n; i++) {
			currpos[i] = m + i;
			mins[i] = i;
			maxs[i] = i;
		}
		
		segtree = new int[4 * size];
		left = new int[4 * size];
		right = new int[4 * size];
		
		build(0, size, 0);
		
		for (int i = 0; i < m; i++) {
			int v = sc.nextInt() - 1;
			int oldpos = currpos[v];
			int newpos = m - i - 1;
			
			update(oldpos, -1, 0);
			mins[v] = 0;
			int val = oldpos - newpos + query(0, newpos, oldpos) - 1;
			if (val > maxs[v])
				maxs[v] = val;
			currpos[v] = newpos;
		}

		CF1288E ex = new CF1288E();
		
		Event[] events = new Event[n];
		for (int i = 0; i < n; i++) {
			events[i] = ex.new Event(currpos[i], i);
		}
		
		Arrays.sort(events);
		
		
		for (int i = 0; i < n; i++) {
			int v = events[i].index;
			if (i > maxs[v])
				maxs[v] = i;
		}
		
		String[] out = new String[n];
		for (int i = 0; i < n; i++) {
			out[i] = Integer.toString(mins[i] + 1) + " " + Integer.toString(maxs[i] + 1);
		}
		
		System.out.println(String.join("\n", out));
		sc.close();
	}
}