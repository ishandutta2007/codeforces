a = [int(i) for i in input().split(' ')]
N = a[0]
K = a[1]
from math import *

tar = 1 - cos(2*pi/N)
def works(x):
  tmp = (4*x*x) / 2 / ((x+1)*(x+1))
  return tmp >= tar

low = 0
upp = 10
eps = 0.000000001
while upp - low > eps:
  mid = (upp + low)/2
  if (works(mid)):upp = mid
  else: low = mid

print(low*K)