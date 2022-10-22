import java.util.*;

public class E{
	final int MAXN = (int)2e5 + 10, SQ = 333;
	int[] a = new int[MAXN], b = new int[MAXN];
	int n;

	int bs(int l, int r, int x){
		int lo = 0, hi = r-l+1;
		while (hi-lo>1){
			int mid = hi+lo>>1;
			if (b[l+mid - 1] < x)
				lo = mid;
			else
				hi = mid;
		}
		return lo;
	}

	int get(int l, int r, int x){
		int ret = 0;
		for (; l%SQ>0 && l < r; l++) if (a[l] < x) ret++;
		for (; l/SQ != r/SQ; l += SQ) ret += bs(l, l+SQ, x);
		for (; l<r; l++) if (a[l] < x) ret++;
		return ret;
	}

	void solve(){
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		int q = sc.nextInt();
		for (int i = 0; i < n; i++) a[i] = b[i] = i;

		long ans = 0;
		while (q-->0){
			int u = sc.nextInt(), v = sc.nextInt();
			u--; v--;
			if (u > v){
				int temp = u;
				u = v;
				v = temp;
			}
			if (u != v){
				int temp = get(u, v, a[v]);
				ans += temp;
				ans -= (v-u-temp);

				temp = get(u+1, v, a[u]);
				ans -= temp;
				ans += (v-u-1-temp);

				{
					temp = a[u];
					a[u] = a[v];
					a[v] = temp;
				}
				int l = u/SQ*SQ;
				for (int i = l; i < l+SQ && i < n; i++) b[i] = a[i];
				Arrays.sort(b, l, Math.min(l+SQ, n));
				
				l = v/SQ*SQ;
				for (int i = l; i < l+SQ && i < n; i++) b[i] = a[i];
				Arrays.sort(b, l, Math.min(l+SQ, n));
			}
			System.out.println(ans);//XXX
		}
	}
	public static void main(String[] argc){
		E sol = new E();
		sol.solve();
	}
}