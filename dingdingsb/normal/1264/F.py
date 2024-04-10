N = int(1.5e9)
mod = int(1e9)
n,a,b = map(int,input().split(' '))
x= ( 614945049 * a ) % mod
y= ( 614945049 * b ) % mod
print( x*N+1, y*N)