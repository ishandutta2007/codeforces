a = set()
string = input()
for i in range(len(string)):
    string = string[-1] + string[:-1]
    a.add(string)
print(len(a))