import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static long pow10(long l) {
		long pow = 1;
		for (int i = 0; i < l; ++i)
			pow *= 10;
		return pow;
	}

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		long ans = 0;
		long n = Integer.parseInt(br.readLine());

		long sz = ("" + n).toString().length();
		for (int l = 1; l < sz; ++l) {
			ans += l * (pow10(l) - pow10(l - 1));
		}
		ans += (n - pow10(sz - 1) + 1) * sz;

		System.out.println(ans);
	}
}