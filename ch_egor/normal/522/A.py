import sys

infile = sys.stdin
outfile = sys.stdout

def main():
    n = int(infile.readline())

    graf = dict()
    graf["polycarp"] = 1
    answer = 1
        
    for i in range(n):
        reposter, buff, poster =[st.lower() for st in infile.readline().split()]
        graf[reposter] = graf[poster] + 1
        answer = max(answer, graf[reposter])

    outfile.write(str(answer))
        
    
main()