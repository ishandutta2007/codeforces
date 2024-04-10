import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.Scanner;

public class CF1284D {
	static int M = 1_000_000_007;
	
	public class Event implements Comparable<Event>{
		int time;
		boolean type;
		int index;
		
		Event (int time, boolean type, int index){
			this.time = time;
			this.type = type;
			this.index = index;
		}

		@Override
		public int compareTo(Event o) {
			int res = Integer.compare(time, o.time);
			if (res != 0) return res;
			if (type == o.type) return 0;
			if (type) return -1;
			return 1;
		}
		
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		Random rd = new Random();
		
		int n = sc.nextInt();
		boolean works = true;
		
		ArrayList<Event> events1 = new ArrayList<Event>();
		ArrayList<Event> events2 = new ArrayList<Event>();
		
		for (int ev = 0; ev < n; ev++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			int d = sc.nextInt();
			
			events1.add(new CF1284D().new Event(a, true, ev));
			events1.add(new CF1284D().new Event(b, false, ev));
			events2.add(new CF1284D().new Event(c, true, ev));
			events2.add(new CF1284D().new Event(d, false, ev));
		}
		
		Collections.sort(events1);
		Collections.sort(events2);
		
		for (int iter = 0; iter < 1; iter ++) {
			long[] hashes = {0, 0};
			long[] weights = new long[n];
			for (int i = 0; i < n; i ++)
				weights[i] = (rd.nextInt() % M);
			
			long curr = 0;
			for (Event e: events1) {
				boolean type = e.type;
				int loc = e.index;
				
				long weight = weights[loc];
				
				if (type) {
					hashes[0] += (curr * weight);
					hashes[0] %= M;
					
					curr += weight;
				}
				else {
					curr -= weight;
				}
				
				curr %= M;
			}
			
			for (Event e: events2) {
				boolean type = e.type;
				int loc = e.index;
				
				long weight = weights[loc];
				
				if (type) {
					hashes[1] += (curr * weight);
					hashes[1] %= M;
					
					curr += weight;
				}
				else {
					curr -= weight;
				}
				
				curr %= M;
			}
			
			long diff = hashes[1] - hashes[0];
			if (diff % M != 0) {
				works = false;
				break;
			}
		}
		
		if (works) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
	
		
		sc.close();
			
	}
}