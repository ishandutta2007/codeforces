import java.util.Scanner;

public class T{

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a[] = {5,7,5};
        for (int i=0;i<3;i++){
            String s = sc.nextLine();
            int cnt = 0;
            for (int j=0;j<s.length();j++){
                char c = s.charAt(j);
                if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                    cnt++;
            }
            if (cnt!=a[i]){
                System.out.print("NO");
                return;
            }
        }
        System.out.print("YES");
    }
}