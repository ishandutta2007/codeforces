/*kitten*/
import java.util.*;
public class Main {
public static void main(String args[]) {
Scanner s = new Scanner(System.in);
int N,M,T,i,j;
String[] in = new String[15];
N = s.nextInt();
M = s.nextInt();
T = s.nextInt();
for(i=0; i<N; i++) in[i] = s.next();
int a = 0;
for(j=0;j<M;j++) {
int c=0;
for(i=0;i<N;i++) if(in[i].charAt(j) == 'Y') c++;
if(c>=T) a++;
}
System.out.println(a);
s.close();
}
}