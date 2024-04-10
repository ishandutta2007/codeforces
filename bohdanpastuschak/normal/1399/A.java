import java.util.Scanner;

public class Main{
	public static void main(String[] argv){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
			int n = sc.nextInt();
			int b[] = new int[101];
			for(int i = 1; i <= 100; ++i){
				b[i] = 0;
			}
			
			for(int i = 0; i < n; ++i){
				int x = sc.nextInt();
				b[x]++;
			}

			boolean ans = true;
			for(int i = 1; i <= 100; ++i){
				if (b[i] == 0){
					boolean l = false, r = false;
					for(int j = 1; j < i; ++j){
						l |= b[j] > 0;
					}

					for(int j = i + 1; j <= 100; ++j){
						r |= b[j] > 0;
					}

					ans &= !l || !r;
				}
			}
			
			System.out.println(ans ? "YES" : "NO");						
		}
	}
}