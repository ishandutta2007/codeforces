#include<iostream>
#include<vector>
using namespace std;
#define R register int
int main(){
	cout.flush();
    int n,k,a,b;
    cin>>n>>k;
    vector<int>E;
    for(R i=1;i<k+2;i++){
        cout<<"? ";
        for(R j=1;j<k+2;j++){
        	if(i!=j){
        		cout<<j<<' ';
			}
		}
        puts("");
        cin>>a>>b;
        E.push_back(b);
    }
    a=E[0];
    b=E.size();
    for(R i=1;i<b;i++){
    	if(E[i]>a){
    		a=E[i];
		}
	}
    k=0;
    for(R i=0;i!=b;i++){
    	if(E[i]==a){
    		k++;
		}
	}
    cout<<"! "<<k;
    return 0;
}