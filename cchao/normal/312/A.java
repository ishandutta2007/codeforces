import java.util.*;
public class A312{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String tmp = scanner.nextLine();
        int n = Integer.parseInt(tmp);
        while(n-- > 0) {
            String s = scanner.nextLine();
            int a = 0, b = 0;
            if(s.startsWith("miao.")) a = 1;
            if(s.endsWith("lala.")) b = 1;
            if(a==b)
                System.out.println("OMG>.< I don't know!");
            else if(a==1)
                System.out.println("Rainbow's");
            else
                System.out.println("Freda's");
        }
    }
}