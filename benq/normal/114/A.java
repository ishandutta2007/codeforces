import java.util.*;
import java.lang.*;
import java.io.*;

public class B {
    public static void main(String[] args) {
        // System.out.println("HI");
        Scanner in = new Scanner(System.in);
        long k = in.nextLong(), l = in.nextLong(), c = 0;
        long k1 = k;
        while (k1<l) {
            k1 *= k;
            c++;
        }
        if (k1 == l) {
            System.out.println("YES");
            System.out.println(c);
        } else System.out.println("NO");
    }
}