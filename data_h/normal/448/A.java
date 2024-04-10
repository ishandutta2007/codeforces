import java.util.Scanner;


public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int a = 0;
		int b = 0;
		for(int i = 0; i < 3; i++) {
			int x = in.nextInt();
			a += x;
		}
		for(int i = 0; i < 3; i++) {
			int x = in.nextInt();
			b += x;
		}
		int n = in.nextInt();
		System.out.println((a + 4) / 5 + (b + 9) / 10 <= n ? "YES" : "NO");
	}
}