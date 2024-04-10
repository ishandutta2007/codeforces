import java.io.*;
import java.lang.*;
import java.util.*;
import static java.lang.Integer.parseInt;

public class Main {
    public static void main(String[] args) throws IOException {
        class Reader {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = null;
            
            String next() throws IOException {
                while (st == null || !st.hasMoreTokens()) {
                    st = new StringTokenizer(br.readLine());
                }
                return st.nextToken();
            }
        }
        
        Reader inp = new Reader();
        int d = parseInt(inp.next()), k = parseInt(inp.next());
        int[] a = new int[d + 1];
        int[] b = new int[d + 1];
        
        for (int i = 0; i < d; ++i) {
            a[i] = parseInt(inp.next());
            b[i] = parseInt(inp.next());
        }
        
        for (int i = d; i-- > 0; ) {
            a[i] += a[i + 1];
            b[i] += b[i + 1];
        }
        
        if (a[0] > k || b[0] < k) {
            System.out.println("NO");
            return ;
        }
        
        System.out.println("YES");
        for (int i = 0; i < d; ++i) {
            a[i] -= a[i + 1];
            b[i] -= b[i + 1];
            for (int f = a[i]; f <= b[i]; ++f) {
                if (f + a[i + 1] > k || f + b[i + 1] < k) continue;
                System.out.print(f + " ");
                k -= f;
                break;
            }
        }
    }
}