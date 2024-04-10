#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> VI;

int main(){
	int p,q,l,r;
	cin>>p>>q>>l>>r;
	VI Zi(p);
	VI Zo(p);
	VI Xi(q);
	VI Xo(q);
	for(int i = 0;i < p;++i) cin>>Zi[i]>>Zo[i];
	for(int i = 0;i < q;++i) cin>>Xi[i]>>Xo[i];
	
	int c = 0;
	
	for(int k = l;k <= r;++k){
		bool x = false, z = false;
		int xi = 0,xo = 0,zi = 0,zo = 0;
		int kx,kz;
		for(int i = 0;i < 2*(p+q);++i){
			if(x) kx = Xo[xo]+k;
			else kx = Xi[xi]+k;
			if(z) kz = Zo[zo];
			else kz = Zi[zi];
			
			if(kx < kz){
				if(z){
					++c;
					i = 2*(q+p+1);
					break;
				}
				if(x) ++xo;
				else ++xi;
				x = !x;
			}
			else if(kx > kz){
				if(x){
					++c;
					i = 2*(q+p+1);
					break;
				}
				if(z) ++zo;
				else ++zi;
				z = !z;
			}
			else{
				++c;
				i = 2*(q+p+1);
				break;
			}
			
			if(xo >= q || zo >= p) i = 2*(q+p+1);
		}
	}
	cout<<c<<endl;
}