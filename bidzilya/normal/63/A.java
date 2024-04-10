import java.util.Scanner;

public class MyTask {
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		String name[] = new String[n];
		int top[] = new int[n];
		sc.nextLine();
		
		for (int i=0;i<n;i++){
			String temp = sc.nextLine();
			
			char c[] = temp.toCharArray();
			int j=0;
			while (c[j]!=' ')j++;
			
			name[i] = "";
			for (int k=0;k<j;k++)
				name[i] += c[k];
			
			if (c[j+1]=='r')
				top[i] = 0;
			else
			if (c[j+1]=='c' && c[j+2]=='h')
				top[i] = 1;
			else
			if (c[j+1]=='w')
				top[i] = 1;
			else
			if (c[j+1]=='m')
				top[i] = 2;
			else
				top[i] = 3;
		}
		
		String ans[] = new String[n];
		int m =0;
		for (int j=0;j<=3;j++)
			for (int i=0;i<n;i++)
				if (top[i]==j)
					ans[m++] = name[i];
		for (int i=0;i<n;i++)
			System.out.println(ans[i]);
	}
}