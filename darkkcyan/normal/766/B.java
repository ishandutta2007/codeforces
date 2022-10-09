import java.io.*;
import java.lang.*;
import java.util.*;
import java.util.stream.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        int[] a = Arrays.stream(in.readLine().split(" "))
            .mapToInt(Integer::parseInt)
            .sorted()
            .toArray();

        for (int i = 2; i < n; ++i) {
            if (a[i] < a[i - 1] + a[i - 2]) {
                System.out.println("YES");
                return;
            }
        }

        System.out.println("NO");
    }
}