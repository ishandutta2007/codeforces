import std.stdio;
import std.conv;
import std.array;
import std.algorithm;
void main()
{
	int num;
	readf("%d\n",&num);
	string[]s=split(readln());
	int[]a;
	for(int i=0;i<s.length;i++)a~=to!int(s[i]);
	int ans=0;
	for(int i=1;i<a.length-1;i++)if(a[i-1]==1&&a[i+1]==1)a[i]=1;
	for(int i=0;i<a.length;i++)ans+=a[i];
	writeln(ans);
	readln();
}