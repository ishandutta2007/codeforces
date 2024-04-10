import java.util.*;

public class B{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), q = sc.nextInt();
		int[] p = new int[n];
		for (int i = 0; i < n; i++)
			p[i] = sc.nextInt() - 1;
		
		while (q-->0){
			int l = sc.nextInt()-1, r = sc.nextInt(), pos = sc.nextInt()-1;
			int cnt = 0;
			for (int i = l; i < r; i++)
				if (p[i] < p[pos]) cnt++;
			System.out.println(cnt==pos-l?"Yes":"No");
		}
	}
}