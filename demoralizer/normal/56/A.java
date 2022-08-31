import java.util.*;

public class Demo
{
	public static void main (String[] args)
	{
		String w[]={"ABSINTH","BEER","BRANDY","CHAMPAGNE","GIN","RUM","SAKE","TEQUILA","VODKA","WHISKEY","WINE"};
		Scanner sc=new Scanner(System.in);
		int n=Integer.parseInt(sc.nextLine()),c=0;
		for(int i=0;i<n;i++){
			String a=sc.nextLine();	if(a.charAt(0)>='0'&&a.charAt(0)<='9')
			if(Integer.parseInt(a)<18){
				c++;
				continue;
			}
			for(int j=0;j<w.length;j++)
				if(a.equals(w[j])){c++;break;}
		}
		System.out.println(c);
	}
}