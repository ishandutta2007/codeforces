def nextInt():
    return int(input())

def nextInts():
    return map(int,input().split())

n = nextInt()
a = nextInts()
m = nextInt()
b = nextInts()
print(max(a),max(b))