import java.util.Scanner;
import java.math.BigInteger;
import java.util.Random;
import java.util.ArrayList;

public class Main{
    public static Scanner scanner;
    public static BigInteger query(BigInteger x){
	System.out.println("sqrt "+x.toString());
	String str=scanner.next();
	return new BigInteger(str);
    }
    public static void main(String[] args){
	scanner=new Scanner(System.in);
	String str=scanner.next();
	BigInteger N=new BigInteger(str);
	Random rand=new Random();
	int t=0;
	ArrayList<BigInteger> list=new ArrayList<BigInteger>();
	list.add(N);
	long start=System.currentTimeMillis();
	while((++t<100)&&(System.currentTimeMillis()-start<5500)){
	    BigInteger x;
	    do{
		x=new BigInteger(N.bitLength(),rand);
	    }while(x.compareTo(N)>=0);
	    BigInteger y=query(x.multiply(x).mod(N));
	    BigInteger diff=x.subtract(y).abs();
	    if(diff.equals(BigInteger.ONE)||diff.equals(N)) continue;
	    ArrayList<BigInteger> tmp=new ArrayList<BigInteger>();
	    for(int i=0;i<list.size();i++){
		BigInteger a=list.get(i).gcd(diff);
		BigInteger b=list.get(i).divide(a);
		if(!a.equals(BigInteger.ONE)) tmp.add(a);
		if(!b.equals(BigInteger.ONE)) tmp.add(b);
	    }
	    list=tmp;
	}
	System.out.print("! "+list.size());
	for(int i=0;i<list.size();i++){
	    System.out.print(" ");
	    System.out.print(list.get(i).toString());
	}
	System.out.println();
    }
}