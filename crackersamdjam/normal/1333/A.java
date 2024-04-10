import java.util.*;
import java.io.*;
public class cf1333A{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		int t = readInt();
		while(t --> 0){
			int n = readInt(), m = readInt();
			int[][] a = new int[n][m];
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					a[i][j] = (i+j)%2;
				}
			}
			if(n%2 == 0){
				a[n-1][0] = 0;
			}
			else if(m%2 == 0){
				a[0][m-1] = 0;
			}

			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++)
					System.out.print(a[i][j] == 1 ? "W" : "B");
				System.out.println();
			}
		}
	}


	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}