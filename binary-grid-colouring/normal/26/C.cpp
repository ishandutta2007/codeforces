#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

int X,Y,a,b,c;
char ans[123][123];

void put(int x, int y, int dx, int dy)
{
    char ch = 'a' + (x%5) + 5 * (y%5);
    for(int i=0;i<dx;i++){
    	for(int j=0;j<dy;j++){
    		ans[x+i][y+j] = ch;
		}
	} 
}

bool put_c(int x, int y)
{
    if(x == X-1 || y == Y-1) return false;
    if(c == 0) return false;
    put(x,y,2,2); 
	c--;
    return true;
}

bool put_a(int x, int y)
{
    if(y == Y-1) return false;
    if(x == X-1)
	{
        if(a == 0) return false;
        put(x,y,1,2); 
		a--;
    } 
	else 
	{
        if(a <= 1) return false;
        put(x,y,1,2); 
		a--;
        put(x+1,y,1,2); 
		a--;
    }
    return true;
}

bool put_b(int x, int y)
{
    if(x == X-1) return false;
    if(y == Y-1)
	{
        if(b == 0) return false;
        put(x,y,2,1); 
		b--;
    } 
	else 
	{
        if(b <= 1) return false;
        put(x,y,2,1); 
		b--;
        put(x,y+1,2,1); 
		b--;
    }
    return true;
}

int main()
{
    cin >> X >> Y >> a >> b >> c;
    for(int i=0;i<X;i++){
    	for(int j=0;j<Y;j++){
    		ans[i][j] = '?';
		}
	}
    
    bool failed = false;
    if(X%2 == 1)
	{
		for(int i=0;i<Y;i++)
		{
			if(ans[X-1][i] == '?' && !put_a(X-1,i)) failed = true;
		}
	}
    if(Y%2 == 1)
	{
		for(int i=0;i<X;i++)
		{
			if(ans[i][Y-1] == '?' && !put_b(i,Y-1)) failed = true;
		}
	}
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++)
		{
			if(ans[i][j] == '?' && !put_c(i,j) && !put_a(i,j) && !put_b(i,j)) failed = true;
		}
	}
    
    if(failed)
	{
        cout<<"IMPOSSIBLE"<< endl;
    } 
	else
	{
		for(int i=0;i<X;i++)
        {
            string s;
            for(int j=0;j<Y;j++){
            	s += ans[i][j];
			}
            cout << s << endl;
        }
    }
    return 0;
}