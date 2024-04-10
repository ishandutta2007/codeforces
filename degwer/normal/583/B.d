import std.stdio;
import std.array;
import std.conv;
import std.algorithm;
int[]get()
{
	string[]s=split(readln());
	int[]r;
	for(int i=0;i<s.length;i++)r~=to!int(s[i]);
	return r;
}
void main()
{
	int num;
	readf("%d\n",&num);
	int[]a=get();
	int ans=0;
	int now=0;
	for(;;)
	{
		for(int i=0;i<num;i++)
		{
			if(now>=a[i])
			{
				a[i]=1000000000;
				now++;
			}
		}
		if(now==num)break;
		ans++;
		for(int i=num-1;i>=0;i--)
		{
			if(now>=a[i])
			{
				a[i]=1000000000;
				now++;
			}
		}
		if(now==num)break;
		ans++;
	}
	writeln(ans);
	readln();
}