import java.util.*;

public class Sol{
	public static void main(String[] argc){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), k = sc.nextInt(); k--;
		int[] a = new int[n];
		for (int i = 0; i < n; i++) a[i] = sc.nextInt();
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (a[i] >= a[k] && a[i] > 0) ans++;
		System.out.printf("%d\n", ans);
	}
}