import java.util.Scanner;

public class Sol{
	public static void main(String[] argc){
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		System.out.println((a+c-1)/c * ((b+c-1)/c));
	}
};