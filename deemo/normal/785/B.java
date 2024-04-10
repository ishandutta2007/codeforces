import java.util.*;


public class B{
	class Segment{
		public int l, r;
		public int compareTo(Segment seg){return this.l - seg.l;}
	}

	void solve(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Segment[] a = new Segment[n];
		for (int i = 0; i < n; i++){
			a[i] = new Segment();
			a[i].l = sc.nextInt();
			a[i].r = sc.nextInt();
		}

		int m = sc.nextInt();
		Segment[] b = new Segment[m];
		for (int i = 0; i < m; i++){
			b[i] = new Segment();
			b[i].l = sc.nextInt();
			b[i].r = sc.nextInt();
		}

		int tr = (int)1e9, ans = 0, tl = -1;
		for (Segment s:b){
			tr = Math.min(tr, s.r);
			tl = Math.max(tl, s.l);
		}
		for (Segment s:a){
			ans = Math.max(ans, s.l - tr);
			ans = Math.max(ans, tl - s.r);
		}

		System.out.println(ans);
	}
	public static void main(String[] argc){
		B sol = new B();
		sol.solve();
	}
}