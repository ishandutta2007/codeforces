import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt();
        int[] co = new int[2000];
        char[][] g = new char[2000][2000];

        for (int i = 0; i < n; ++i) {
            String S = in.next();
        	for (int j = 0; j < m; ++j) {
            	g[i][j] = S.charAt(j);
            	if (g[i][j] == '1') co[j] ++;
        	}
        }
        
        for (int i = 0; i < n; ++i) {
            int need = 0;
            for (int j = 0; j < m; ++j)
                if (co[j] == 1 && g[i][j] == '1') 
                    need = 1;
                    
            if (need == 0) {
                System.out.println("YES");
                return;
            }
        }
        
        System.out.println("NO");
    }
}