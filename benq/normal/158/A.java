import java.util.*;
import java.io.*;

public class HelloWorld {
	public static void main(String []args) {
				Scanner in = new Scanner(System.in);
				int n = in.nextInt();
				int k=in.nextInt(), y,z=1, count = 0;

				for (; count < k; ++count) {
					z=in.nextInt();
					if (z == 0) {
						System.out.println(count);
						System.exit(0);
					}
				}
				for (;count<n;++count) {
					y=in.nextInt();
					if (y != z) {
						System.out.println(count);
						System.exit(0);
					}
				}
				System.out.println(count);
				System.exit(0);
	}
}