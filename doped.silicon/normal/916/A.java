import java.util.*;
import java.lang.*;
import java.io.*;
public class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		int b2=b%10;
		int a2=c%10;
		int b1=b/10;
		int k=0;
		int a1=c/10;
		if(a1==7||a2==7||b1==7|b2==7)
		System.out.println(0);
		while(!(a1==7||a2==7||b1==7|b2==7))
		{
			
				k++;
				c-=a;
				if(c<0)
				{
				c+=60;
				b-=1;
				if(b<0)
				b+=24;
				}
				 b2=b%10;
		 a2=c%10;
		 b1=b/10;
		
		 a1=c/10;
				
				if(a1==7||a2==7||b1==7|b2==7)
	                        	System.out.println(k);
			
		}
	}
}