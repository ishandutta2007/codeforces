import std.stdio;
import std.array;
import std.algorithm;
import std.conv;
import std.bigint;
import std.string;
BigInt calc(BigInt n)
{
	BigInt med=n;
	int[]v;
	for(;;)
	{
		if(n==0)break;
		v~=n%10;
		n/=10;
	}
	BigInt cnt=0;
	BigInt t=1;
	for(int i=0;i<v.length;i++)
	{
		BigInt[]x;
		x.length=10;
		BigInt mm=med/(t*10);
		BigInt mm1=mm*10;
		for(int j=0;j<=9;j++)
		{
			x[j]+=mm*t;
			if(mm1+j<med/t)x[j]+=t;
			else if(mm1+j==med/t)x[j]+=med-(mm1+j)*t+1;
		}
		for(int j=0;j<=9;j++)cnt+=x[j]*j;
		t*=10;
	}
	return cnt;
}
BigInt get(BigInt a)
{
	BigInt beg=0,end="10000000000000000000000";
	for(;;)
	{
		if(beg==end)break;
		BigInt med=(beg+end)/2;
		BigInt cnt=calc(med);
		if(cnt<a)beg=med+1;
		else end=med;
	}
	return beg;
}
void main()
{
	//for(int i=0;i<200;i++)writeln(i," ",calc(to!BigInt(i)));
	BigInt a=to!BigInt(chomp(readln()));
	BigInt[]dat;
	dat.length=1000;
	for(int i=0;i<1000;i++)dat[i]=-1;
	for(int i=0;;i++)
	{
		BigInt t;
		BigInt x=a*i;
		x=get(x);
		t=calc(x);
		//writeln(x," ",get(x)," ",t," ",t%a);
		if(dat[to!int(t%a)]!=-1&&dat[to!int(t%a)]!=x)
		{
			writeln(dat[to!int(t%a)]+1," ",x);
			break;
		}
		dat[to!int(t%a)]=x;
	}
	readln();
}