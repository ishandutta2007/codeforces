def ivu(uname):
    if 1 > len(uname) or len(uname) > 16:
        return 0
    for ch in uname:
        if ch not in "qwertyuiopasdfghhjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890_":
            return 0
    return 1

def do():
    f = input()
    if f.count('@') != 1:
        return 0
    uname, hname = f.split('@')
    if hname.count('/') > 1:
        return 0
    if ivu(uname) == 0:
        return 0
    resource = "a"
    if hname.count('/') == 1:
        hname, resource = hname.split('/')
    if 1 > len(hname) or len(hname) > 32:
        return 0
    for i in hname.split('.'):
        if ivu(i) == 0:
            return 0
    if ivu(resource) == 0:
        return 0
    return 1

if do() == 0:
    print("NO")
else:
    print("YES")