import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader i = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(i.readLine());
        int n = Integer.parseInt(st.nextToken()), v = Integer.parseInt(st.nextToken());
        if (n-1 <= v) {
            System.out.println (n-1);
            return;
        }
        int cost = v;
        for (int x = 2; x <= n-v; x++) {
            cost += x;
        }
        System.out.println (cost);
    }
}