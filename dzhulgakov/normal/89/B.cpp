#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

int n;

struct Widget
{
	LL x,y;
	int type;
	LL border,spacing;
	vector<Widget*> a;
	bool calced;
	Widget()
	{
		calced = false;
		border=spacing=0;
		x=y=0;
	}
	void calc()
	{
		if (type == -1) return;
		if (calced) return;
		calced = true;
		REP(i,SZ(a))
			a[i]->calc();
		x=0,y=0;
		if (SZ(a) == 0) return;
		if (type == 0)
		{
			REP(i,SZ(a))
			{
				x += a[i]->x;
				y = max(y,a[i]->y);
			}
			x += (SZ(a)-1)*spacing;
		}
		else
		{
			REP(i,SZ(a))
			{
				y += a[i]->y;
				x = max(x,a[i]->x);
			}
			y += (SZ(a)-1)*spacing;
		}
		x+=2*border;
		y+=2*border;
	}
};

char buf[10240];
map<string, Widget*> a;

int main()
{
	//freopen("data.in","r",stdin);

	gets(buf);
	sscanf(buf,"%d",&n);
	REP(i,n)
	{
		gets(buf);
		char cmd[1024],w[1024],arg[1024];
		sscanf(buf,"%s",cmd);
		if (strchr(buf,'.') != 0)
		{
			REP(i,strlen(buf))
				if (buf[i]=='.' || buf[i]=='(' || buf[i]==')' || buf[i]==',')
					buf[i] = ' ';
			sscanf(buf,"%s %s %s",w,cmd,arg);
			if (a[string(w)]->type == -1)
				printf("BAD");
			if (strcmp(cmd,"pack") == 0)
			{
				a[string(w)]->a.push_back(a[string(arg)]);
			}
			else
			{
				int x;
				sscanf(arg,"%d",&x);
				if (strcmp(cmd,"set_border") == 0)
					a[string(w)]->border = x;
				else if (strcmp(cmd,"set_spacing") == 0)
					a[string(w)]->spacing = x;
				else
					printf("BAD!");
			}
		}
		else
		{
			REP(i,strlen(buf))
				if (buf[i]=='.' || buf[i]=='(' || buf[i]==')' || buf[i]==',')
					buf[i] = ' ';
			Widget *q = new Widget();
			sscanf(buf,"%s %s",cmd,w);
			if (strcmp(cmd, "Widget") == 0)
			{
				q->type = -1;
				sscanf(buf,"%s %s %lld %lld",cmd,w,&q->x,&q->y);
			}
			else if (strcmp(cmd, "HBox") == 0)
				q->type = 0;
			else if (strcmp(cmd, "VBox") == 0)
				q->type = 1;
			else
				printf("NOTGOOD!");
			a[string(w)] = q;
		}
	}
	for (map<string,Widget*>::iterator it = a.begin(); it != a.end(); ++it)
	{
		it->second->calc();
		cout << it->first << " " << it->second->x << " " << it->second->y << endl;
	}
	return 0;
}