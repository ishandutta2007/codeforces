import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class Main {
	
	public static class Query {
		int x, y, v;
		Query() { x = y = v = 0; }
		Query(int , int , int ) { x = ; y = ; v = ; }
	}
	final static int Dollar1 = 998244353;
	public static int fastpow(int , int ) {
		int res = 1;
		while ( != 0) {
			if (( & 1) == 1) res = (int) ((long) res *  % Dollar1);
			 = (int) ((long)  *  % Dollar1);
			 >>= 1;
		}
		return res;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n, m;
		String [] tin = br.readLine().split(" ");
		n = Integer.parseInt(tin[0]);
		m = Integer.parseInt(tin[1]);
		Query[] arr = new Query[n * m];
		int bak = 0;
		for (int i = 1; i <= n; ++i) {
			tin = br.readLine().split(" ");
			for (int j = 1; j <= m; ++j)
				arr[bak++] = new Query(i, j, Integer.parseInt(tin[j - 1]));
		}
		tin = br.readLine().split(" ");
		final int qx = Integer.parseInt(tin[0]);
		final int qy = Integer.parseInt(tin[1]);
		Arrays.sort(arr, new Comparator<Query>() {
			public int compare(Query a, Query b) {
				return a.v - b.v;
			}
		} );
		int [] f = new int[n * m];
		final int sv = arr[0].v;
		int lstv = 0, prex = 0, prey = 0, pref = 0, prep = 0;
		for (int i = 0; i != n * m; ++i) {
			while (arr[lstv].v != arr[i].v) {
				prex = (prex + arr[lstv].x) % Dollar1;
				prey = (prey + arr[lstv].y) % Dollar1;
				pref = (pref + f[lstv]) % Dollar1;
				prep = (int) ((prep + (long) arr[lstv].x * arr[lstv].x + (long) arr[lstv].y * arr[lstv].y) % Dollar1);
				++lstv;
			}
			// System.out.println("DEBUG : " + i + " " + f[i] + " " + lstv + " " + prex + " " + prey + " " + pref + " " + prep);
			if (arr[i].v != sv) {
				f[i] = (int) ((pref + prep - 2L * ((long) prex * arr[i].x + (long) prey * arr[i].y) % Dollar1) * fastpow(lstv, Dollar1 - 2) 
						% Dollar1 + ((long) arr[i].x * arr[i].x + (long) arr[i].y * arr[i].y) % Dollar1 % Dollar1);
				if (f[i] < 0) f[i] = f[i] + Dollar1;
			}
			// System.out.println("DEBUG : " + i + " " + f[i] + " " + lstv + " " + prex + " " + prey + " " + pref + " " + prep);
			if (arr[i].x == qx && arr[i].y == qy) {
				System.out.println(f[i]);
				break;
			}
		}
	}

}