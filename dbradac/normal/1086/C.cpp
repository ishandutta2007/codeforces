#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<20, A = 26;

int n, k;
int kamo[A], odakle[A];
char s[MAX], a[MAX], b[MAX];

int DEB=0;

void dopuni() {
  //  REP(i, k) TRACE(i _ kamo[i]);
  
  REP(i, k) {
    if (kamo[i] != -1) continue;
    REP(j, k) {
      if (odakle[j] == -1) {
	kamo[i] = j;
	odakle[j] = i;
	break;
      }
    }
  }

  // TRACE("DOP");
  // REP(i, k) TRACE(i _ kamo[i]);
}

void dopuni_min(int ind) {
  FOR(i, ind, n) {
    int c = s[i] - 'a';
      
    if (kamo[c] == -1) {
      int mn = -1;
      REP(j, k) {
	if (odakle[j] == -1) {
	  mn = j;
	  break;
	}
      }

      assert(mn != -1);
      kamo[c] = mn;
      odakle[mn] = c;
    }
  }

  dopuni();
}

void dopuni_max(int ind) {  
  FOR(i, ind, n) {
    int c = s[i] - 'a';
    
    if (kamo[c] == -1) {
      int mx = -1;
      for (int j=k-1; j>=0; j--) {
	if (odakle[j] == -1) {
	  mx = j;
	  break;
	}
      }

      assert(mx != -1);
      kamo[c] = mx;
      odakle[mx] = c;
    }
  }

  dopuni();
}

void trans(char *nov) {
  REP(i, n)
    nov[i] = (char) ('a' + kamo[s[i]-'a']);
  nov[n] = 0;
}

int done=0;
char kraj[MAX];
void check() {
  if (done) return;
  
  trans(kraj);
  //  if (DEB) TRACE(kraj);
  //  REP(i, k) TRACE(i _ kamo[i]);

  if (strcmp(kraj, a) >= 0 && strcmp(kraj, b) <= 0) {
    //    TRACE(a _ kraj _ b);
    done = 1;
    printf("YES\n");
    REP(j, k) printf("%c", (char) (kamo[j] + 'a'));
    printf("\n");
  }
}

void go() {
  REP(st, 2) {
    memset(kamo, -1, sizeof kamo);
    memset(odakle, -1, sizeof odakle);
    
    int ck = 0;

    //    TRACE(st);
    REP(i, n) {
      //      TRACE(i);
      //      TRACE(st _ i);
      if (ck) break;
      
      int c = s[i] - 'a';
      //      TRACE(i _ c);
      
      if (a[i] != b[i]) {
	if (kamo[c] != -1) {
	  if (!st) {
	    dopuni_max(i+1);
	    ck = 1;
	    check();
	    break;
	  }
	  else {
	    dopuni_min(i+1);
	    ck = 1;
	    check();
	    break;
	  }
	}
	
	REP(j, k) {
	  if (odakle[j] == -1) {
	    if (j > a[i] - 'a' && j < b[i] - 'a') {
	      kamo[c] = j;
	      odakle[j] = c;
	      //	      TRACE(j _ c);
	      
	      dopuni();
	      check();
	      ck = 1;
	      break;
	    }
	  }
	}

	//	TRACE(st _ i);
	
	if (ck) break;
	if (!st && odakle[a[i]-'a'] == -1) {
	  kamo[c] = a[i] - 'a';
	  odakle[a[i]-'a'] = c;
	  dopuni_max(i+1);		
	  check();
	  ck = 1;
	}
	else if (st && odakle[b[i]-'a'] == -1) {
	  kamo[c] = b[i] - 'a';
	  odakle[b[i]-'a'] = c;
	  //	  TRACE(b[i]-'a' _ c);
	  
	  dopuni_min(i+1);
	  check();
	  ck = 1;
	}
      }
      else {
	if (kamo[c] == -1 && odakle[a[i]-'a'] == -1) {
	  kamo[c] = a[i] - 'a';
	  odakle[a[i]-'a'] = c;
	  //	  TRACE(a[i]-'a' _ c);
	}
      }
    }

    //    REP(i, k) TRACE(i _ kamo[i]);
    dopuni();
    check();
  }
}

int main()
{
  int t;
  scanf("%d", &t);

  while(t--) {
    done = 0;
    scanf("%d", &k);
    scanf(" %s %s %s", s, a, b);
    //    TRACE(k _ s _ a _ b);
    n = (int) strlen(s);

    //    if (k == 26 && n == 1 && s[0] == 'b' && a[0] == 'a' && b[0] == 'a') DEB = 1;
    //    else DEB = 0;
    go();
    if (!done) printf("NO\n");
  }

  return 0;
}