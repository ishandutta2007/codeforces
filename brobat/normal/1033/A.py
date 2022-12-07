def solve(n,bx,by,ax,ay,cx,cy):
    if(bx>ax and bx<cx):
        return "NO"
    if(bx<ax and bx>cx):
        return "NO"
    if(by>ay and by<cy):
        return "NO"
    if(by<ay and by>cy):
        return "NO"
    return "YES"

n = int(input())
ax,ay = map(int,input().split())
bx,by = map(int,input().split())
cx,cy = map(int,input().split())

print(solve(n,ax,ay,bx,by,cx,cy))