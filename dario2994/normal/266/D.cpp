#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAXN 210
#define INF 1<< 28
using namespace std;

int N,M;
vector <pair <int,int> > archi;
vector <int> lung;
int d[MAXN][MAXN];

pair <int,int> est[MAXN];
int tt[MAXN];

int main(){
	//~ ifstream cin("input.txt");
	cin >> N >> M;
	for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)d[i][j]=INF;
	for(int i=1;i<=N;i++)d[i][i]=0;
	for(int i=0;i<M;i++){
		int a,b,l;
		cin >> a >> b >> l;
		archi.push_back(make_pair(a,b));
		lung.push_back(l);
		d[a][b]=min(d[a][b],l);
		d[b][a]=d[a][b];
	}
	//Floyd-Warshall
	for(int v=1;v<=N;v++)for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)d[i][j]=min(d[i][j],d[i][v]+d[v][j]);
	double ris=1e9;
	for(int t=0;t<M;t++){//Ciclo su ogni arco, trovando il caso migliore se metto il ristorante su quell'arco
		//L'idea  disegno nel piano delle funzioni che sono delle spezzate prima parallele a x e poi a -x. Trovo il punto in cui la maggiore di queste ha valore minimo.
		int A=archi[t].first;
		int B=archi[t].second;
		int l=lung[t];
		
		//Costruisco est, che tiene i 2 "vertici" delle spezzate che studio.
		for(int i=1;i<=N;i++){
			est[i-1]=make_pair(d[A][i],d[B][i]);
		}
		sort(est,est+N);
		//tt contiene il punto in cui la spezzata si "spezza". Tengo qui e dopo le coordinate raddoppiate cos posso continuare a lavorare negli int.
		for(int i=0;i<N;i++)tt[i]=l+est[i].second-est[i].first;
		
		//Gestisco i casi estremi, cio in cui mi conviene mettere il ristorante in uno dei 2 vertici.
		int res=2*est[N-1].first;
		int mm=0;
		for(int i=0;i<N;i++)mm=max(mm,est[i].second);
		res=min(res,2*mm);
		
		//Faccio una sweep line che "segue" il contorno alto formato dalle spezzate.
		int ss=N-1, dd=-1;
		while(0<=ss){
			int t1=tt[ss];
			if( dd!=-1 ){
				int t2=l+est[dd].second-est[ss].first;
				if( t2<t1 )res=min( res, 2*est[ss].first+t2 );
			}
			if ((dd==-1) or est[ss].second>est[dd].second)dd=ss;
			while(ss>=0 and tt[ss]<=t1)ss--;
		}
		
		ris=min(ris,((double)res)/2.0);
	}
	cout << ris << "\n";
}