import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader i = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(i.readLine());
        int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken()), z = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(i.readLine());
        int a = Integer.parseInt(st.nextToken()), b = a + Integer.parseInt(st.nextToken()), c = b + Integer.parseInt(st.nextToken());
        //System.out.println (a + " " + b + " " + c);
        if (a >= x) {
            b-=x;
            c-=x;
        }
        else {
            System.out.println ("NO");
            return;
        }
        //System.out.println (a + " " + b + " " + c);
        if (b >= y) c -= y;
        else {
            System.out.println ("NO");
            return;
        }
        if (c >= z) System.out.println ("YES");
        else System.out.println ("NO");
    }
}