import std.stdio;
import std.array;
import std.conv;
import std.algorithm;
void main()
{
	int num;
	readf("%d\n",&num);
	bool[]a=new bool[num],b=new bool[num];
	a[]=false,b[]=false;
	for(int i=0;i<num*num;i++)
	{
		int x,y;
		readf("%d %d\n",&x,&y);
		if((!a[x-1])&&(!b[y-1]))
		{
			write(i+1," ");
			a[x-1]=b[y-1]=true;
		}
	}
	readln();
}