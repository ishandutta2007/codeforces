import java.util.Scanner;
import java.util.*;
public class project{
    public static void main(String[]args)
    {
	Scanner s = new Scanner(System.in);
	
	int n =s.nextInt(), k=s.nextInt();
	
	 
          String str = s.next();
          str='Y'+str;
          str+='Y';
         char[] x = str.toCharArray();
          
          
          int cur =0 ,ans = 0;
          boolean t=false;
          for(int i=1;i<=n;i++)
          {
                    if(t && x[i]=='N')
                    {
                              cur++;
                    }
                    if(!t && x[i]=='N')
                    {
                              t=true;
                              cur++;
                    }
                    if(x[i]!='N')
                    {
                        if (ans < cur)
                        ans = cur;
                             
                              t=false;
                              cur=0;
                    }
          }
          
          if (ans < cur) ans = cur;
          //cout<<ans<<endl;
          if(ans>k)
          {
                    System.out.println("NO");
                   
          }
          else
          {
          boolean vyv = false;
          for(int i=1;i<=n-k+1;i++)
          {
                    //cout<<x<<endl;
                    //cout<<i-1<<"  "<<i+k<<endl;
                    //cout<<x[i-1]<<" "<<x[i+k]<<endl;
                    if((x[i-1]=='Y' || x[i-1]=='?') && (x[i+k]=='Y' || x[i+k]=='?'))
                    {
                              t=true;
                              for(int j=i;j<k+i;j++)
                              {
                                        if(x[j]=='Y')
                                                  t=false;
                              }
                              if(t)
                              {
                                        System.out.println("YES");
                                      vyv = true;
                                      break;
                              }
                    }
          }
          if (!vyv)
          System.out.println("NO");
          }
    }
}