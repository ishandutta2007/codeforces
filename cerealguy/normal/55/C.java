import java.io.*;

public class C {

	public static void main(String[] args) throws IOException {
		int n = nextInt(), m = nextInt();
		int k = nextInt();
		for (int i = 0; i < k; i++) {
			int x = nextInt(), y = nextInt();
			if (x <= 5 || y <= 5 || x >= n - 4 || y >= m - 4) {
				System.out.println("YES");
				return;
			}
		}
		System.out.println("NO");
	}

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
}