import java.util.*;

public class A{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt(), b = sc.nextInt();
		for (int i = 1; ; i++){
			if ((i&1)==1)
				a -= i;
			else
				b -= i;
			if (a < 0){
				System.out.println("Vladik");
				return;
			}
			if (b < 0){
				System.out.println("Valera");
				return;
			}
		}
	}
}