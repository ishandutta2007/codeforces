import java.util.*;

public class B {

	static boolean[] operations;
	static long ans;

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		long[] a = new long[4];
		for (int i = 0; i < 4; i++) {
			a[i] = s.nextInt();
		}
		operations = new boolean[3];
		for (int i = 0; i < 3; i++) {
			operations[i] = s.next().charAt(0) == '*';
		}
		ans = Long.MAX_VALUE;
		get(a);
		System.out.println(ans);
	}

	static void get(long[] a) {
		if (a.length == 1) {
			ans = Math.min(ans, a[0]);
		} else {
			int n = a.length;
			long[] b = new long[n - 1];
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					long result = operations[4 - n] ? a[i] * a[j] : a[i] + a[j];
					int cnt = 0;
					for (int k = 0; k < n; k++) {
						if (k != i && k != j)
							b[cnt++] = a[k];
					}
					b[cnt++] = result;
					get(b);
				}
			}
		}
	}
}