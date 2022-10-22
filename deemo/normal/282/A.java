import java.util.*;

public class Sol{
	public static void main(String[] argc){
		Scanner sc = new Scanner(System.in);
		int x = 0, n = sc.nextInt();
		while (n-->0){
			String s = sc.next();
			if (s.contains("+")) x++;
			else x--;
		}
		System.out.println(x);
	}
}