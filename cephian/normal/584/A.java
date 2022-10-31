import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt(), t = s.nextInt();
        if(n == 1 && t == 10) {
            System.out.println("-1");
        } else {
        String str = "1";
        while(str.length() != n)
            str += "0";
        BigInteger b = new BigInteger(str);
        BigInteger m = new BigInteger(t + "");
        while(!b.mod(m).equals(BigInteger.ZERO))
            b = b.add(BigInteger.ONE);
        System.out.println(b);
        }
        s.close();
    }
}