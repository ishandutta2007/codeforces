import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
			int a = sc.nextInt();
			int b = sc.nextInt();
			int w = (a + b - 1) / b * b;
			System.out.println(w - a);
		}
	}
}