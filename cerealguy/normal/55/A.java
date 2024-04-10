import java.util.*;

public class A {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        System.out.println((n & n - 1) == 0 ? "YES" : "NO");
    }
}