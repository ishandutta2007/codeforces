import java.util.*;

public class Sol{
	public static void main(String[] argc){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), ans = 0;
		while (n-->0){
			int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
			a += b+c;
			if (a>1)
				ans++;
		}
		System.out.println(ans);
	}
}