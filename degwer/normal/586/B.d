import std.stdio;
import std.conv;
import std.algorithm;
import std.array;
int[]get()
{
	string[]a=split(readln());
	int[]r;
	for(int i=0;i<a.length;i++)r~=to!int(a[i]);
	return r;
}
void main()
{
	int num;
	readf("%d\n",&num);
	int[]a=get(),b=get(),x=get();
	int mini1=1000000000,mini2=1000000000;
	for(int i=0;i<x.length;i++)
	{
		int now=0;
		for(int j=0;j<i;j++)now+=a[j];
		now+=x[i];
		for(int j=i;j<b.length;j++)now+=b[j];
		if(mini1>now)
		{
			mini2=mini1;
			mini1=now;
		}
		else if(mini2>now)mini2=now;
	}
	printf("%d\n",mini1+mini2);
	readln();
}