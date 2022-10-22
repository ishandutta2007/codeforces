#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
	int h,a,b;
};
bool mar[10][10][10];
int main()
{
	int h,a,b,i,no=0;
	string pla[10][10];
	cin>>h>>a>>b;
	for(i=0;i<h;i++)
		for(int j=0;j<a;j++)
			cin>>pla[i][j];
	node sta;
	sta.h=0;
	cin>>sta.a>>sta.b;
	sta.a--;
	sta.b--;
	queue<node> q;
	q.push(sta);
	const int dir[][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
	while(!q.empty())
	{
		node head=q.front();
		q.pop();
		if(mar[head.h][head.a][head.b])
			continue;
		no++;
		mar[head.h][head.a][head.b]=true;
		for(i=0;i<6;i++)
		{
			node now;
			now.h=head.h+dir[i][0];
			now.a=head.a+dir[i][1];
			now.b=head.b+dir[i][2];
			if(now.h<0||now.h>=h||now.a<0||now.a>=a||now.b<0||now.b>=b)
				continue;
			if(pla[now.h][now.a][now.b]=='#'||mar[now.h][now.a][now.b])
				continue;
			q.push(now);
		}
	}
	cout<<no;
	return 0;
}
/*1
1 1 1

.

1 1
*/
/*2
2 1 1

.

#

1 1
*/
/*3
2 2 2

.#
##

..
..

1 1
*/
/*4
3 2 2

#.
##

#.
.#

..
..

1 2
*/
/*5
3 3 3

.#.
###
##.

.##
###
##.

...
...
...

1 1
*/