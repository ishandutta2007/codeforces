import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class B {

	// ways to make with n letters
	static long[] f = new long[51];

	static String find(String str, long k) {
		if (k == 1)
			return str;
		int len = str.length();
		long first = f[len - 1];
		// swap
		if (k > first) {
			return "" + str.charAt(1) + str.charAt(0)
					+ find(str.substring(2, str.length()), k - first);
		} else {
			return str.substring(0, 1)
					+ find(str.substring(1, str.length()), k);
		}
	}

	static void print(String str) {
		for (int i = 0; i < str.length(); ++i) {
			System.out.print((int) str.charAt(i));
			if (i == str.length() - 1)
				System.out.println();
			else
				System.out.print(" ");
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		f[0] = f[1] = 1;
		for (int i = 2; i <= 50; ++i)
			f[i] = f[i - 1] + f[i - 2];
		String[] inp = br.readLine().split("\\s+");
		long n = Long.parseLong(inp[0]);
		long k = Long.parseLong(inp[1]);
		String str = "";
		for (int i = 1; i <= n; ++i)
			str += "" + (char) (i);
		String ans = find(str, k);
		print(ans);
	}
}