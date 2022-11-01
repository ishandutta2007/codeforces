import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	static Scanner in = new Scanner(System.in);
	static BigInteger[] a = new BigInteger[600];
	static BigInteger[] b = new BigInteger[600];
	public static void main(String[] args) {
		BigInteger n = in.nextBigInteger();
		a[0] = BigInteger.ONE;
		for (int i = 1; i < a.length; i++) {
			a[i] = a[i-1].multiply(BigInteger.valueOf(12));
		}
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length; j++) {
				if (n.equals(a[i].add(a[j]))) {
					System.out.println("YES");
					System.out.println(1);
					System.out.println(i+j+1);
					int sum = i+j;
					int res = 0;
					for (int ii = 0; ii*2 <= sum; ii++)
						if (ii != i && ii != j) {
							b[res++] = a[ii].add(a[sum-ii]);
						}
					System.out.println(res);
					for (int ii = res-1; ii >= 0; ii--)
						System.out.println(b[ii]);
					return;
				}
			}
		}
		System.out.println("NO");
	}

}