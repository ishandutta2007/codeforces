import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			String[] st = br.readLine().split(" ");
			int a = Integer.parseInt(st[0]);
			int b = Integer.parseInt(st[1]);
			int c = Integer.parseInt(st[2]);
			int d = Integer.parseInt(st[3]);
			ans += (Math.abs(a - c) + 1) * (Math.abs(b - d) + 1);
		}
		System.out.println(ans);
	}
}