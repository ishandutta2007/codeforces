import java.io.*;

public class A {
	static int nextInt() throws IOException {
		int m = 0;
		int c = System.in.read();
		while (c < '0' || c > '9')
			c = System.in.read();
		while (c >= '0' && c <= '9') {
			m = m * 10 + (c - '0');
			c = System.in.read();
		}
		return m;
	}

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int[] a = new int[3];
		for (int i = 0; i < n; i++) {
			a[nextInt() - 1]++;
		}
		int ans = 0;
		for (int i : a) {
			ans = Math.max(ans, i);
		}
		System.out.println(n - ans);
	}
}