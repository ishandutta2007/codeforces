import std.stdio;
import std.array;
import std.conv;
import std.algorithm;
int[] dat;
void main()
{
	int num,query;
	string[]zs=split(readln());
	num=to!int(zs[0]);
	query=to!int(zs[1]);
	string s=readln();
	for(int i=0;i<26;i++)dat~=i;
	for(int i=0;i<query;i++)
	{
		char za,zb;
		zs=split(readln());
		za=to!char(zs[0]);
		zb=to!char(zs[1]);
		int a,b;
		for(int j=0;j<26;j++)
		{
			if(za-'a'==dat[j])a=j;
			if(zb-'a'==dat[j])b=j;
		}
		swap(dat[a],dat[b]);
	}
	for(int i=0;i<num;i++)write(to!char('a'+dat[s[i]-'a']));
	writeln();
	readln();
}