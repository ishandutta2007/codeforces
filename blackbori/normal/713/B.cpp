#include <cstdio>

using namespace std;

struct r{
	int x1,x2,y1,y2;
};

int Ask(int a,int b,int c,int d)
{
	int ret;
	
	printf("? %d %d %d %d\n",a,b,c,d);
	fflush(stdout);
	
	scanf("%d",&ret);
	
	return ret;
}

r Find(int x1,int y1,int x2,int y2)
{
	r ret;
	
	int s,e,m,k;
	
	s=x1, e=x2;
	while(s<=e){
		m = (s+e)/2;
		
		k = Ask(m,y1,x2,y2);
		
		if(k==0) e = m-1;
		else s = m+1;
	}
	ret.x1 = s-1;
	
	s=x1, e=x2;
	while(s<=e){
		m = (s+e)/2;
		
		k = Ask(x1,y1,m,y2);
		
		if(k==0) s = m+1;
		else e = m-1;
	}
	ret.x2 = e+1;
	
	s=y1, e=y2;
	while(s<=e){
		m = (s+e)/2;
		
		k = Ask(x1,m,x2,y2);
		
		if(k==0) e = m-1;
		else s = m+1;
	}
	ret.y1 = s-1;
	
	s=y1, e=y2;
	while(s<=e){
		m = (s+e)/2;
		
		k = Ask(x1,y1,x2,m);
		
		if(k==0) s = m+1;
		else e = m-1;
	}
	ret.y2 = e+1;
	
	return ret;
}

int main()
{
	int n,s,e,m,k;
	int _row1,_row2,_col1,_col2;
	r r1,r2;
	
	scanf("%d",&n);
	
	//row1
	s=1, e=n;
	while(s<=e){
		m = (s+e)/2;
		
		k = Ask(1,1,m,n);
		
		if(k==0) s = m+1;
		else e = m-1;
	}
	_row1 = e+1;
	
	//row2
	s=1, e=n;
	while(s<=e){
		m = (s+e)/2;
		
		k = Ask(m,1,n,n);
		
		if(k==0) e = m-1;
		else s = m+1;
	}
	_row2 = s-1;
	
//	printf("%d %d\n",_row1,_row2);
	if(_row1 < _row2){
		r1 = Find(1,1,_row1,n);
		r2 = Find(_row2,1,n,n);
	}
	else{
	
		//col1
		s=1, e=n;
		while(s<=e){
			m = (s+e)/2;
			
			k = Ask(1,1,n,m);
			
			if(k==0) s = m+1;
			else e = m-1;
		}
		_col1 = e+1;
		
		//col2
		s=1, e=n;
		while(s<=e){
			m = (s+e)/2;
			
			k = Ask(1,m,n,n);
			
			if(k==0) e = m-1;
			else s = m+1;
		}
		_col2 = s-1;
		
		r1 = Find(1,1,n,_col1);
		r2 = Find(1,_col2,n,n);
	}
	
	printf("! %d %d %d %d %d %d %d %d\n",r1.x1,r1.y1,r1.x2,r1.y2,r2.x1,r2.y1,r2.x2,r2.y2);
	fflush(stdout);
	
	return 0;
}