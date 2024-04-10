import java.util.*;

public class C{
	static final int C = (int)5e3 + 10;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n], cnt = new int[C];
		for (int i = 0; i < n; i++){
			a[i] = sc.nextInt();
			cnt[a[i]]++;
		}
		
		int[] d = new int[n+1];
		for (int i = 0; i < n; i++){
			d[i+1] = d[i];
			
			int[] temp = new int[C];
			int bad = 0, x = 0;
			for (int l = i; l >= 0; l--){
				temp[a[l]]++;
				if (temp[a[l]] == 1){
					bad++;
					x ^= a[l];
				}
				if (temp[a[l]] == cnt[a[l]]) bad--;

				if (bad == 0)
					d[i+1] = Math.max(d[i+1], x+d[l]);
			}
		}
		System.out.println(d[n]);
	}
}